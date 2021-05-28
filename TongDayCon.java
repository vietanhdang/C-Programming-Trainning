/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.LinkedList;
import java.util.Scanner;

/**
 *
 * @author vietd
 */
public class getTime {

    static int check(int[] arr, int b, int s) {
        if (arr[b] == s) {
            return -1;
        } else {
            for (int i = 0; i < b; i++) {
                if (arr[b] - s == arr[i]) {
                    return i;
                }
            }
        }

        return -2;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int s = sc.nextInt();
        int[] temp = new int[n];
        temp[0] = arr[0];
        int index = 0;
        for (int i = 1; i < n; i++) {
            temp[i] = temp[i - 1] + arr[i];
            if (temp[i] < s) {
                index = i;
            }
        }
        while (index < n && check(temp, index, s) == -2) {
            index++;
        }
        if (index == n) {
            System.out.println("-1");
        } else {
            for (int i = check(temp, index, s) + 1; i <= index; i++) {
                System.out.print(arr[i] + " ");
            }
        }
    }
}

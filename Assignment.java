/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package assignment;

/**
 *
 * @author vietd
 */
import java.util.LinkedList;
import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Random;

public class Assignment {

    static boolean spBai2(int a, int b, int[] arr) {
        for (int i = a; i < b; i++) {
            if (arr[i] == arr[b]) {
                return false;
            }
        }
        return true;
    }

    static double giaiThua(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * giaiThua(n - 1);
    }

    static void bai2() {
        int arr[] = {0, 1, 5, 4, 0, 1, 2, 3, 5, 4, 0, 1, 2, 3};
        LinkedList<Integer> list = new LinkedList<>();
        int index1 = 0, index2 = 0;
        int n = arr.length;
        while (index1 < n) {
            index2 = index1 + 1;
            while (index2 < n && spBai2(index1, index2, arr) == true) {
                index2++;
            }
            list.add(index2);
            index1 = index2;
        }
        int max = list.get(0);
        int tempIndex1 = 0, tempIndex2 = 0;
        for (int i = 0; i < list.size() - 1; i++) {
            if (list.get(i + 1) - list.get(i) > max) {
                max = list.get(i + 1) - list.get(i);
                tempIndex1 = i;
                tempIndex2 = i + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println("");
        System.out.println("Day con chung dai nhat nam tu phan tu thu: " + (list.get(tempIndex1) + 1) + " toi phan tu thu " + (list.get(tempIndex2)));
        for (int i = list.get(tempIndex1); i < list.get(tempIndex2); i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println("");
    }

    static boolean bai3(int n) { //3
        int sum = 0;
        int k = n;
        while (n != 0) {
            int x = n % 10;
            sum += giaiThua(x);
            if (sum > k) {
                return false;
            }
            n = n / 10;
        }
        if (sum == k) {
            return true;
        }
        return false;
    }

    static void bai4() {
        int[][] list = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        int line1 = 1 - 1, line2 = 2 - 1;
        int n = list.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(list[i][j]);
            }
            System.out.println("");
        }
        System.out.println("");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int t = list[line1][j];
                list[line1][j] = list[line2][j];
                list[line2][j] = t;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(list[i][j]);
            }
            System.out.println("");
        }
    }

    static void bai6() {
        int[][] arr = {{1, 0, 0}, {1, 5, 6}, {7, 8, 9}};
        int k = arr.length;
        int sum = 0;
        int sum1 = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if ((i + j + 2) % 3 == 0) {
                    sum += arr[i][j];
                }
                if (arr[i][j] > 0) {
                    sum1 += arr[i][j];
                }
            }
        }
        System.out.println("Tong cac phan tu trong ma tran ma (i+j) %3 la: " + sum);
        System.out.println("Trung binh cong cac pha tu duong trong ma tran la: " + sum1);
    }

    static void bai7() {
        Scanner sc = new Scanner(System.in);
        int select = 0;
        do {
            clearScreen();
            select = menu();
            switch (select) {
                case 1:
                    dienTichHinhThang();
                    break;
                case 2:
                    dienTichHinhTron();
                    break;
                case 3:
                    dienTichHinhTamGiac();
                    break;
                case 4:
                    theTichKhoiHop();
                    break;
            }
        } while (select != 0);
    }

    static void bai8() { //8
        int n = 1993;
        double a = 72, b = 2.3, c = 1.5;
        double k = a * c;;
        while (a <= k) {
            n++;
            a = (a + a * (b / 100));

        }
        System.out.println("Toi nam: " + n + " thi dan so nuoc ta se gap " + c + " dan so hien tai");
    }

    static void bai9() {
        Scanner sc = new Scanner(System.in);
        double a = sc.nextDouble();
        int i = 0;
        double sum = 1;
        while ((1.0 / giaiThua(i)) >= a) {
            sum += (1.0 / giaiThua(i));
            i++;
        }
        System.out.println(sum);
    }

    static int menu() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Chuong trinh tinh dien tich hinh thang, hinh tron, tam giac va the tich hinh hop");
        System.out.println("Moi ban nhap lua chon");
        System.out.println("1. Tinh dien tich hinh thang");
        System.out.println("2. Tinh dien tich hinh tron");
        System.out.println("3. Tinh dien tinh hinh tam giac");
        System.out.println("4. Tinh the tich khoi hop");
        System.out.println("0. Thoat chuong trinh");
        int n = sc.nextInt();
        if (n > 0 && n < 5) {
            return n;
        }
        return 0;
    }

    static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    static void dienTichHinhThang() {
        Scanner sc = new Scanner(System.in);
        double a;
        do {
            System.out.println("Nhap day lon, day nho, chieu cao");
            a = sc.nextDouble();
            if (a <= 0) {
                break;
            } else {
                double b = sc.nextDouble();
                double c = sc.nextDouble();
                double result = ((a + b) * c) / 2;
                System.out.println("Dien tinh hinh thang cua ban la: " + result);
            }
        } while (a != 0);

    }

    static void dienTichHinhTamGiac() {
        Scanner sc = new Scanner(System.in);
        double a;
        do {
            System.out.println("Nhap chieu dai day, chieu cao: ");
            a = sc.nextDouble();
            if (a <= 0) {
                break;
            } else {
                double b = sc.nextDouble();
                double result = (0.5 * a * b);
                System.out.println("Dien tinh hinh tam tiac cua ban la: " + result);
            }
        } while (a != 0);
    }

    static void dienTichHinhTron() {
        Scanner sc = new Scanner(System.in);
        double a;
        do {
            System.out.println("Nhap do dai ban kinh: ");
            a = sc.nextDouble();
            if (a <= 0) {
                break;
            } else {
                double result = 2 * 3.14 * a;
                System.out.println("Dien tinh hinh tron cua ban la: " + result);
            }
        } while (a != 0);
    }

    static void theTichKhoiHop() {
        Scanner sc = new Scanner(System.in);
        double a;
        do {
            System.out.println("Nhap chieu dai chieu rong cua day va chieu cao cua khoi hop: ");
            a = sc.nextDouble();
            if (a <= 0) {
                break;
            } else {
                double b = sc.nextDouble();
                double c = sc.nextDouble();
                double result = a * b * c;
                System.out.println("The tich khoi hop la: " + result);
            }
        } while (a != 0);
    }

    static void bai11() {
        int[][] list = {{1, 0, 0}, {1, 5, 6}, {7, 8, 9}};
        int index = 0;
        int n = list.length;
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = 0;
            for (int j = 0; j < n; j++) {
                System.out.print(list[i][j]);
            }
            System.out.println("");
        }
        System.out.println("");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (list[i][j] == 0) {
                    arr[j] = 1;
                }
            }
        }
        while (index < n) {
            if (arr[index] == 1) {
                for (int i = 0; i < n; i++) {
                    list[i][index] = 0;
                }
            }
            index++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(list[i][j]);
            }
            System.out.println("");
        }
    }

    static void bai13() {
        Scanner sc = new Scanner(System.in);
        int oddCount = 0;
        int enter = 1;
        double sum = 0;
        while (enter != 0) {
            enter = sc.nextInt();
            if (enter > 0) {
                sum += Math.sqrt(enter);
            } else {
                if (enter % 2 != 0) {
                    oddCount++;
                }
            }
        }
        System.out.println("a. Tong can bac 2 cua cac so duong trong day la: " + sum);
        System.out.println("b. So am ma le trong day la: " + oddCount);

    }

    static void bai14() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int uocSNT = 2;
        System.out.print("Cac uoc so nguyen to cua " + n + " la: ");
        while (n != 1) {
            if (n % uocSNT == 0) {
                System.out.print(uocSNT + " ");
                n /= uocSNT;
            } else {
                uocSNT++;
            }
        }
    }

    static void bai15() {
        int[] temp = new int[1000];
        int n = 1000;
        for (int i = 0; i < n; i++) {
            temp[i] = i;
        }
        Random randomGenerator = new Random();
        for (int i = 0; i < n; i++) {

            int t = temp[i];
            double randomDouble = randomGenerator.nextInt(1000) % 1000;
            int r = (int) randomDouble;
            temp[i] = temp[r];
            temp[r] = t;
        }

        try {
            //Bước 1: Tạo đối tượng luồng và liên kết nguồn dữ liệu
            File f = new File("C:/Users/vietd/Desktop/mydata.txt");
            FileWriter fw = new FileWriter(f);
            //Bước 2: Ghi dữ liệu
            for (int i = 0; i < n; i++) {
                fw.write(temp[i] + "\n");
            }
            //Bước 3: Đóng luồng
            fw.close();
        } catch (IOException ex) {
            System.out.println("Loi ghi file: " + ex);
        }

        try {
            //Bước 1: Tạo đối tượng luồng và liên kết nguồn dữ liệu
            File f = new File("C:/Users/vietd/Desktop/mydata.txt");
            FileReader fr = new FileReader(f);
            //Bước 2: Đọc dữ liệu
            BufferedReader br = new BufferedReader(fr);
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
            //Bước 3: Đóng luồng
            fr.close();
            br.close();
        } catch (Exception ex) {
            System.out.println("Loi doc file: " + ex);
        }
    }

    static void bai18() {
        int arr[] = {1, 1, 1, 1, 1, 1, 1, 1};
        LinkedList<Integer> list = new LinkedList<>();
        int n = arr.length;
        System.out.println("Day ban dau la: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
            if (arr[i] == 0) {
                list.add(i);
            }
        }
        if (list.isEmpty()) {
            System.out.println("");
            System.out.println("Khong co day con toan phan tu khong");
        } else {
            int count = 0;
            int max = 0;
            int index1 = 0, index2 = 0;
            for (int i = 0; i < list.size() - 1; i++) {
                if (list.get(i + 1) - list.get(i) == 1) {
                    count++;
                    if (count > max) {
                        max = count;
                        index2 = i + 1;
                    }
                } else {
                    count = 0;
                }
            }
            max++;
            System.out.println("");
            System.out.println("Day con dai nhat chi chua 0 se nam o vi tri: " + (list.get(index2) + 2 - max) + " toi vi tri: " + (list.get(index2) + 1));
            for (int i = list.get(index2) - max + 1; i <= list.get(index2); i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println("");
            System.out.println("Do dai cua day con la: " + max);
        }

    }

    static boolean spBai19(int n) {
        long temp = n;
        long get = 0, result = 0;
        while (n != 0) {
            get = n % 10;
            result = result * 10 + get;
            n /= 10;
        }
        if (temp == result) {
            return true;
        }
        return false;
    }

    static void bai19() {
        System.out.println("so tu nhien nho hon 100 binh phuong la Palindrome la: ");
        for (int i = 1; i < 100; i++) {
            if (spBai19(i * i) == true) {
                System.out.print(i + " ");
            }
        }
        System.out.println("");
    }

    static void bai20() {
        int[] arr = {1, 2, 3, 5, 4, 3, 2, 1};
        int n = arr.length;
        int[] temp = new int[n];
        System.out.println("Mang ban dau la: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
            temp[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    temp[j] = 0;
                }
            }
        }
        System.out.println("");
        System.out.println("Cac so khac nhau trong mang la: ");
        for (int i = 0; i < n; i++) {
            if (temp[i] != 0) {
                System.out.print(arr[i] + " ");
            }
        }
        System.out.println("");
    }

    static boolean spBai21(int n) {
        int sum = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                sum += i;
            }
            if (sum > n) {
                return false;
            }
        }
        if (sum == n) {
            return true;
        }
        return false;
    }

    static void bai21() {
        System.out.println("So hoan thien la: ");
        for (int i = 0; i < 1000; i++) {
            if (spBai21(i) == true) {
                System.out.print(i + " ");
            }
        }
        System.out.println("");
    }

    public static void main(String[] args) {
        giaiPTBac1 sc = new giaiPTBac1(0, 1);
        sc.solve();
    }
}

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
class Rectangle1 {

    private int length;
    private int width;

    public Rectangle1() {
    }

    public Rectangle1(int length, int width) {
        this.length = length;
        this.width = width;
    }

    public int getLength() {
        return length;
    }

    public int getWidth() {
        return width;
    }

    public void setLength(int length) {
        this.length = length;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    @Override
    public String toString() {
        return "[" + "length=" + length + ", width=" + width + "]";
    }

    public int area() {
        return length * width;
    }
}

class Box extends Rectangle1 {

    private int height;

    public Box() {
        super();
    }

    public Box(int height, int length, int width) {
        super(length, width);
        this.height = height;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int area() {
        return 2 * (getHeight() * getLength() + getWidth() * getHeight() + getHeight() * getLength());
    }
    public int volumn(){
        return getLength()*getWidth()*getHeight();
    }

}
public class Rectangle {

    public static void main(String[] args) {
        Rectangle1 r = new Rectangle1(2, 5);
        System.out.println("Rectangle: " + r.toString());
        System.out.println("Area: " + r.area());
        Box b= new Box(2, 2, 2);
        System.out.println("Box: "+ b.toString());
        System.out.println("Area: "+ b.area());
        System.out.println("Volumn: "+ b.volumn());
                
    }
}

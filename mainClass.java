class Shape
{
	String name;
    
	Shape(String newName) {name = newName;}

    void print() {System.out.print(name);}
    void draw() {System.out.println("error");}
    double area() {return 0.0;}
}

class Circle extends Shape
{
	double radius;
	static final double PI = 3.14;

	Circle(String newName, double newRadius) 
    {
    	super(newName);
        radius = newRadius;
    }
    
	void print() {System.out.println(name + "(" + radius + ") : " + area());}
	void draw() {System.out.println(".");}
	double area() {return PI*radius*radius;}
}

class Triangle extends Shape
{
	double base;
	double height;

	Triangle(String newName, double newBase, double newHeight)
    {
    	super(newName);
        base = newBase;
        height = newHeight;
    }

    void print() {System.out.println(name + "(" + base + ", " + height + ") : " + area());}
    void draw() {System.out.println("..");}
    double area() {return base*height*0.5;}
}

class Square extends Shape
{
	double length;

    Square(String newName, double newLength) 
    {
    	super(newName);
        length = newLength;
    }

    void print() {System.out.println(name + "(" + length + ") : " + area());}
    void draw() {System.out.println("...");}
    double area() {return length*length;}
}

class Rectangle extends Square
{
	double width;

    Rectangle(String newName, double newLength, double newWidth)
    {
    	super(newName, newLength);
        width = newWidth;
    }

    void print() {System.out.println(name + "(" + length + ", " + width + ") : " + area());}
    void draw() {System.out.println("....");}
    double area() {return length*width;}
}

class Picture
{
	class ListNode
    {
    	Shape data;
        ListNode next;

        ListNode(Shape newData, ListNode newNext)
        {
        	data = newData;
            next = newNext;
        }
    }

    ListNode head;
    Picture() {head = null;}
    void add(Shape sh) {head = new ListNode(sh, head);}
	void printAll()
    {
    	ListNode current = head;
        while (current != null)
        {
        	current.data.print();
            current = current.next;
        }
    }
    void drawAll()
    {
    	ListNode current = head;
        while (current != null)
        {
        	current.data.draw();
            current = current.next;
        }
    }
    double totalArea()
    {
    	double total = 0.0;
        ListNode current = head;
        while (current != null)
        {
        	total += current.data.area();
            current = current.next;
        }
        return total;
    }
}

public class mainClass
{
	public static void main(String[] args)
    {
    	Picture pic = new Picture();

        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);

        pic.add(new Triangle("FirstTriangle", a, b));
        pic.add(new Triangle("SecondTriangle", a-1, b-1));

        pic.add(new Circle("FirstCircle", a));
        pic.add(new Circle("SecondCircle", a-1));

        pic.add(new Square("FirstSquare", a));
        pic.add(new Square("SecondSquare", a-1));

        pic.add(new Rectangle("FirstRectangle", a, b));
        pic.add(new Rectangle("SecondRectangle", a-1, b-1));

        pic.printAll();
        pic.drawAll();
        System.out.println("Total : " + pic.totalArea());
    }
}


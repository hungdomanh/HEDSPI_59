// class FreshJuice {

//    enum FreshJuiceSize{ SMALL, MEDIUM, LARGE }
//    FreshJuiceSize size;
// }

// public class Simple {

//    public static void main(String args[]){
//       FreshJuice juice = new FreshJuice();
//       juice.size = FreshJuice. FreshJuiceSize.MEDIUM ;
//       System.out.println("Size: " + juice.size);
//    }
// }

// package edu.doannhg.basic;

// vi du phan biet hai lenh print va println
// public class Simple {
// 	public static void main(String args[]) {

// 		// lenh print
// 		System.out.print("VietJack ");
// 		System.out.print("chuc cac ban ");
// 		System.out.print("hoc tot!!!");
// 		System.out.print("\n---------------\n");

// 		// lenh println
// 		System.out.println("VietJack ");
// 		System.out.println("chuc cac ban ");
// 		System.out.println("hoc tot!!!");

// 	}

// }

// public class Simple{ 
//    public void tuoiCon(){
//       int tuoi = 0;
//       tuoi = tuoi + 10;
//       System.out.println("Tuoi con la : " + tuoi);
//    }
   
//    public static void main(String args[]){
//       Simple test = new Simple();
//       test.tuoiCon();
//    }
// }

// import java.io.*;

// public class Simple{
//    // Bien instance nay la nhin thay cho bat ky lop con nao.
//    public String ten;
   
//    // Bien hocphi la chi nhin thay cho lop Simple.
//    private double hocphi;
   
//    // Bien ten duoc gan trong constructor. 
//    public Simple (String tenSV){
//       ten = tenSV;
//    }

//    // Bien hocphi duoc gan mot gia tri.
//    public void setHocPhi(double hp){
//       hocphi = hp;
//    }
   
//    // Phuong thuc nay in chi tiet ve Simple.
//    public void inThongTin(){
//       System.out.println("Ho va ten: " + ten );
//       System.out.println("Hoc phi: " + hocphi);
//    }

//    public static void main(String args[]){
//       Simple sv1 = new Simple("Nguyen Van Doan");
//       sv1.setHocPhi(4000);
//       sv1.inThongTin();
//    }
// }


// import java.io.*;

// public class Simple{
//    // Bien hocphi la mot bien private static
//    private static double hocphi;

//    // FACULTY la mot constant
//    public static final String FACULTY = "KhoaIT ";

//    public static void main(String args[]){
//       hocphi = 4000;
//       System.out.println(FACULTY+"hocphi trung binh:"+hocphi);
//    }
// }


// public class Simple{
   
//    int Giaxe;

//    public Simple(String ten){
//       // Contructor nay co mot tham so la ten.
//       System.out.println("Ten xe la :" + ten ); 
//    }
//    public void setGia( int gia ){
//        Giaxe = gia;
//    }

//    public int getGia( ){
//        System.out.println("Gia mua xe la :" + Giaxe ); 
//        return Giaxe;
//    }

//    public static void main(String []args){
//       /* Tao doi tuong */
//       Simple Xecuatoi = new Simple( "Toyota" );

//       /* Goi mot phuong thuc lop de thiet lap gia xe */
//       Xecuatoi.setGia( 1000000000 );

//       /* Goi mot phuong thuc lop khac de lay gia xe */
//       Xecuatoi.getGia( );

//       /* Ban cung co the truy cap bien instance nhu sau */
//       System.out.println("Gia tri bien :" + Xecuatoi.Giaxe ); 
//    }
// }

class MyClass {
   int x = 10;
   
   // Sau day la constructor
   // MyClass() {
   //    x = 10;
   // }
}

public class Simple {

   public static void main(String args[]) {
      MyClass t1 = new MyClass();
      MyClass t2 = new MyClass();
      System.out.println(t1.x + " " + t2.x);
   }
}
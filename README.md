# 
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bkt02_tranhylinh;

import java.util.Scanner;

/**
 *
 * @author 陳国才
 */
public class HoaDon {
    protected String ma;
    protected String ngaylap;
    protected String nguoiban;
    protected String nguoiMua;
    protected String tensp;
    protected int sl;
    protected double dg;
    public static double thueVAT= 0.1;

    public HoaDon(String ma, String ngaylap, String nguoiban, String nguoiMua, String tensp, int sl, double dg) {
       this.ma = ma;
            if( ma.startsWith("HD")==false)
                this.ma="HD"+this.ma;
        this.ngaylap = ngaylap;
        this.nguoiban = nguoiban;
        this.nguoiMua = nguoiMua;
        this.tensp = tensp;
        this.sl = sl;
        this.dg = dg;
    }

    public HoaDon() {
        this.ma= " HD001";
        this.nguoiban="Nguyen Hoang";
        this.nguoiMua="Tran Hy Linh";
        this.tensp= "may say sinh to";
        this.sl= 2;
        this.dg=2500;
    }

    public String getMa() {
        return ma;
    }

    public void setMa(String ma) {
         this.ma = ma;
            if( ma.startsWith("HD")==false)
                this.ma="HD"+this.ma;
    }

    public String getNgaylap() {
        return ngaylap;
    }

    public void setNgaylap(String ngaylap) {
        this.ngaylap = ngaylap;
    }

    public String getNguoiban() {
        return nguoiban;
    }

    public void setNguoiban(String nguoiban) {
        this.nguoiban = nguoiban;
    }

    public String getNguoiMua() {
        return nguoiMua;
    }

    public void setNguoiMua(String nguoiMua) {
        this.nguoiMua = nguoiMua;
    }

    public String getTensp() {
        return tensp;
    }

    public void setTensp(String tensp) {
        this.tensp = tensp;
    }

    public int getSl() {
        return sl;
    }

    public void setSl(int sl) {
        this.sl = sl;
    }

    public double getDg() {
        return dg;
    }

    public void setDg(double dg) {
        this.dg = dg;
    }

    public static double getThueVAT() {
        return thueVAT;
    }

    public static void setThueVAT(double thueVAT) {
        HoaDon.thueVAT = thueVAT;
    }
    
     public double tinhThanhTien(){
    if(sl>1000)
        return sl*dg-0.04*sl*dg;
    else 
        return sl*dg;
    }
    public double tinhTienThue(){
        return tinhThanhTien()*thueVAT;
    }
    public double tinhTongTien(){
        return tinhThanhTien()-tinhTienThue();
    }
    public void nhap(){
        Scanner nhap= new Scanner (System.in );
        System.out.println("nhap ma hoa don: ");
        setMa(nhap.nextLine());
        System.out.println("nhap ngay lap: ");
        ngaylap=nhap.nextLine();
        System.out.println("nhap ten nguoi ban: ");
        nguoiban= nhap.nextLine();
        System.out.println("nhap ten nguoi mua: ");
        nguoiMua= nhap.nextLine();
        System.out.println("nhap ten san pham: ");
        tensp=nhap.nextLine();
        System.out.println("nhap so luong: ");
        sl= nhap.nextInt();
        System.out.println("nhap don gia: ");
        dg= nhap.nextDouble();
    }

    @Override
    public String toString() {
        return "HoaDon(" + "ma=" + ma + ", nguoiban=" + nguoiban + ", nguoiMua=" +
                nguoiMua + ", tensp=" + tensp + ", sl=" + sl + ", dg=" + dg +",thanhtien="+tinhThanhTien()+
                ",thueVAT="+tinhTienThue()+",tongtien="+tinhTongTien()+')';
    }
    public void xuat(){
        System.out.println(this.toString());
    }
    
}

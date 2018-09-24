
public class Complex{
    private double re, im;

    Complex(double re,double im){
        this.re=re;
        this.im=im;
    }

    Complex(){
        this.re=0;
        this.im=0;
    }

    Complex(Complex A){
        this.re=A.re;
        this.im=A.im;
    }

    public Complex conjugate(Complex A){
        this.re=A.re;
        this.im=-A.im;
    }

    public Complex sum(Complex A, Complex B){
        this.re=A.re+B.re;
        this.im=A.im+B.im;
    }

    public Complex sub(Complex A, Complex B){
        this.re=A.re-B.re;
        this.im=A.im-B.im;
    }

    public Complex mul(Complex A, Complex B){
        this.re=A.re*B.re - A.im*B.im;
        this.im=A.re*B.im + A.im*B.re;
    }

    public Complex div(Complex A, Complex B){
        this.re=(A.re*B.re + A.im*B.im)/(pow(B.re,2)+pow(B.im,2));
        this.im=(B.re*A.im - A.re*B.im)/(pow(B.re,2)+pow(B.im,2));
    }
}

public class FFT{
    private Complex A[];

    private int bitshift(int index){
        Boolean[] index_vec=new Boolean[8];
        int index_copy=index;
        
        for(int i=7; i>=0; i--){
            if(index_copy<pow(2,i)){
                index_vec[i]=false;
                continue;}
            else{
                index_vec[i]=(Boolean)index_copy%2;
            }
        }

        return;
    }
}
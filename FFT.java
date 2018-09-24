import java.util.Arrays;
import static java.lang.Math.pow;
import static java.lang.Math.sin;
import static java.lang.Math.cos;
import static java.lang.Math.PI;

class Complex{
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

    public Complex conjugate(){
        return new Complex(this.re, -this.im);
    }

    public Complex sum(Complex A){
        return new Complex(this.re+A.re, this.im+A.im);
    }

    public Complex sub(Complex A){
        return new Complex(this.re-A.re, this.im-A.im);
    }

    public Complex mul(Complex A){
        return new Complex((this.re*A.re - this.im*A.im), (this.re*A.im + this.im*A.re));
    }

    public Complex div(Complex A){
        return new Complex((this.re*A.re + this.im*A.im)/(pow(A.re,2)+pow(A.im,2)),((A.re*this.im - this.re*A.im)/(pow(A.re,2)+pow(A.im,2))));
    }

    public Complex jmul(){
        return new Complex(-this.im, this.re);
    }

    public Complex twiddlemul(int n, int k, int N){
        if(n==0){return this.mul(new Complex(1,0));}
        else{return this.mul(new Complex(cos((double)(2*PI*n*k/N)),-sin(cos((double)(2*PI*n*k/N)))));}
    }
}

public class FFT{
    private Complex X[];
    private int N;
    
    FFT(){
        this.X=new Complex[0];
        this.N=0;
    }

    FFT(Complex x[]){
        
        this.X=new Complex[x.length];
        this.N=x.length;
        
        for(int i=0; i<x.length; i++){this.X[i]=x[i];}
    }
    
    private int bitshift(int index, int m_size){
        Boolean bitstream[]=new Boolean[m_size];
        int index_copy=index;

        for(int i=m_size-1; i>=0; i--){
            if(index_copy<pow(2,i)){
                bitstream[i]=false;
                continue;}
            else{
                if(index_copy%2==1){bitstream[i]=true;}
                else{bitstream[i]=false;}
                index_copy=index_copy/2;
            }
        }
        
        index_copy=0;

        for(int i=0; i<m_size; i++){
            if(bitstream[i]){index_copy+=pow((double)2,(double)m_size-1-i);}
        }

        return index_copy;
    }

    private void butterfly1(Complex In[], int begin, int end, Complex Out[]){
        int middlecount=begin-end/2;
        
        for(int i=begin; i<=middlecount; i++){
                Out[i]=In[i].sum(In[i+middlecount+1]);
                if(i<middlecount/2){Out[i+middlecount+1]=Out[i];}
                else{Out[i+middlecount+1]=Out[i].jmul();}            
        }
    }

    private void butterfly2(Complex In[], int begin, int end, int k, int N, Complex Out[]){
        int middlecount=begin-end/2;
        Complex basis = new Complex();

        for(int i=begin; i<=middlecount; i++){
            basis= In[i].sum(In[i+middlecount+1]);
            Out[i]= basis.twiddlemul(i,k,N);
            Out[i+middlecount+1]=basis.twiddlemul(3*i, k, N);
        }

    }

    public static void main(String[] args) {
        System.out.println("Teste bitshift");
        FFT A=new FFT();
    }
}
function B = butterfly(X, depth, total_length)
    X_length=length(X);
    TMP=zeros(1,X_length);
    
    if X_length<=2
        TMP(1)=X(1)+X(2);
        TMP(2)=X(1)-X(2);
        B=TMP;
        return;
    else
        for j=1:X_length/2
            TMP(j)=X(j)+X(j+(X_length/2));
        end;
        n=0;
        for j=X_length/2+1:X_length;
            TMP(j)=(-X(j)+X(j-(X_length/2)))*exp((-2i*pi*n)/(total_length/depth)));
            n=n+1;
        end
        B=horzcat(butterfly(TMP(1:X_length/2),depth+1, total_length), butterfly(TMP((X_length/2)+1:X_length),depth+1,total_length));
        return
    end
    
end 
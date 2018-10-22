function B2 = butterfly2(X, depth, total_length)
    X_length=length(X);
    TMP=zeros(1,X_length);
    
    if X_length<=2
        TMP(1)=X(1)+X(2);
        TMP(2)=X(1)-X(2);
        B2=TMP;
        return;
    else
        n=0;
        for j=1:X_length/2
                TMP(j)=(X(j)+X(j+(X_length/2)))*exp(-1i*(2*pi*n*depth)/total_length);
                n=n+1;
        end
        n=0;
        for j=((X_length/2)+1):X_length
                TMP(j)=(X(j)-X(j-(X_length/2)))*exp(-1i*(2*pi*3*n*depth)/total_length);
                n=n+1;
        end
        B2=horzcat(butterfly1(TMP(1:X_length/2),depth+1,total_length), butterfly1(TMP((X_length/2)+1:X_length),depth+1,total_length));
        return
    end
    
end 
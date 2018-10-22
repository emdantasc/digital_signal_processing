function B1 = butterfly1(X, depth, total_length)
    X_length=length(X);
    TMP=zeros(1,X_length);
    
    if X_length<=2
        TMP(1)=X(1)+X(2);
        TMP(2)=X(1)-X(2);
        B1=TMP;
        return;
    else
        for j=1:X_length
            if (j<=X_length/2)
                TMP(j)=X(j)+X(j+(X_length/2));
            elseif (j>(X_length/2) && j<=(X_length/2)+(X_length/4))
                TMP(j)=-X(j)+X(j-(X_length/2));
            else
                TMP(j)=(-X(j)+X(j-(X_length/2)))*(-1i);
            end   
        end
        B1=horzcat(butterfly1(TMP(1:X_length/2),depth+1, total_length), butterfly2(TMP((X_length/2)+1:X_length),depth+1,total_length));
        return
    end
    
end 
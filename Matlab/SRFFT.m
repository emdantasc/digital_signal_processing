function Y=SRFFT(y)
    TMP=butterfly1(y, 0, length(y));

    index=0:length(y)-1;
    rev_index=bitrevorder(index);
    rev_index=rev_index+1;

    for i=1:length(y);
        Y(i)=TMP(rev_index(i));
    end

end
function SustA = sustitucionatras(A,b)
    T=size(A);
    if(T(1)~=T(2))%checar si es matriz cuadrada
        disp('no es una matriz cuadrada');
        return;
    end
    B=size(b);
    if(T(1)~=B(1))&&(T(1)~=B(2))%checar si el n?mero de valores independientes del vector corresponde con el n?mero de ecuaciones 
        disp('vector de valores independientes incorrecto')
        return;
    end
    Aumentada=zeros(T(1),T(2)+1);
    for i=1:T(1)%ciclo para hacer la matriz aumentada partiendo de la matriz A y el vector de valores independientes
        for j=1:T(2)+1
            if(j~=T(2)+1)
                Aumentada(i,j)=A(i,j);
            else
                Aumentada(i,j)=b(i);
            end
        end
    end 
    disp(Aumentada);
    if(~triangularS(A))%checar si es triangular superior
        disp('MAtriz no es triangular superior');
        return;
    end
    if(rank(A)~=rank(Aumentada))%checar la compatibilidad del sistema
        disp('sistema incompatible')
        return;
    else
        if(det(A)==0)
            disp('sistema compatible indeterminado');
            return;
        end
    end
    %comenzar susticuci?n hacia atr?s
    S=zeros(T(1),1);%vector de soluciones
    n=T(1);
    S(n)=b(n)/A(n,n);
    for i=1:n-1 % sustituci?n inversa
        r=0; 
        for j=0:i-1
            r=r-A(n-i,n-j)*S(n-j);
        end
        S(n-i)=(b(n-i)+r)/A(n-i,n-i);
    end %fin de la sustituci?n
    for i=1:T(1)
        sprintf(strcat('variable_',int2str(i),'=', num2str(S(i))))
    end
end
function check = triangularS(A)%funci?n para revisar si es triangular superior
    check=1;
    T=size(A);
    for i=2:T(1)
        for j=1:i-1
            if(A(i,j)~=0)
                check=0;
                break;
            end
        end
        if(check==0)
            break;
        end
    end
end
function adelante = sustitucionadelante(A,b)
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
    if(~triangularI(A))
        disp('MAtriz no es triangular inferior');
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
    %comenzar sustitucion hacia adelante, usaremos la ?ltima columna de la
    %matriz aumentada en lugar de b
    S=zeros(T(1),1);%vector de soluciones
    n=T(1);
    S(1)=Aumentada(1,n+1)/A(1,1);
    for i=1:n
        r=0; 
        for j=1:i-1
            r=r-A(i,j)*S(j);
        end
        S(i)=(Aumentada(i,n+1)+r)/A(i,i);
    end %fin de la sustituci?n hacia adelante
    for i=1:T(1)
        sprintf(strcat('variable_',int2str(i),'=', num2str(S(i))))
    end
end
function check=triangularI(A)
    check=1;
    T=size(A);
    for i=2:T(2)
        for j=1:i-1
            if(A(j,i)~=0)
                check=0;
                break;
            end
        end
        if(check==0)
            break;
        end
    end
end
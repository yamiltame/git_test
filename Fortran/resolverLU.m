function []=resolverLU(A,b)
    clc;
    T=size(A);%Tama?o de la matriz
    n=T(2);
    [L,U]=DescompLU(A)%descomposicion en LU
    y=sustadelante(L,b)%resolver para el primer bloque con sustitucion hacia adelante
    x=sustatras(U,y)%sustituci?n hacia atr?s para Ux=y
end
function [L,U]= DescompLU(A)
    if det(A)==0
        disp('es una matriz singular, no existe unica factorizacion');
        return;
    end
    clc;
    T=size(A);
    if(T(1)~=T(2))%checar si es matriz cuadrada
        disp('no es una matriz cuadrada');
        return;
    end
    n=T(1);
    L=zeros(n);%la matris inferior
    for i=1:n;
        L(i,i)=1;%diagonal de 1's
    end
    for j=1:n-1%eliminaci?n gausiana sin pivoteo para la matriz U 
        for i = j :(n-1)
            m=A(i+1,j)/A(j,j);
            L(i+1,j)=m;% los factores de la matriz L
            for k=j:n
                A(i+1,k)=A(i+1,k)-A(j,k)*m;
            end
        end
    end
    U=A;
end
function adelante = sustadelante(A,b)
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
    adelante=S;
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
function SustA = sustatras(A,b)
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
    SustA=S;
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
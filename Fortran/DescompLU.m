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
    L=zeros(n);
    for i=1:n;
        L(i,i)=1;
    end
    for j=1:n-1
        disp(A);
        %A=cambiafila(A,j,obtenerpivote(A,j));
        for i = j :(n-1)
            m=A(i+1,j)/A(j,j);
            L(i+1,j)=m;
            for k=j:n
                A(i+1,k)=A(i+1,k)-A(j,k)*m;
            end
            disp('paso de elim');
            disp(A);
        end
    end
    U=A;
end
function int=diferenciasdivididas(A,valores)
    clc;
    disp('TABLA DE VALORES');
    disp(A);
    disp('valores para evaluar');
    disp(valores);
    S=size(A);
    V=size(valores);
    if(V(1)==1)
        k=V(2);
    else
        k=V(1);
    end
    if(V(1)~=1 && V(2)~=1) %CHECAR QUE LOS VALORES PARA EVALUAR LA INTERPOLACION SEAN UN VECTOR
        disp('no es un conjunto de valores');
        return;
    end
    if(S(1)~=2 && S(2)~=2)%CHECAR QUE SEA UNA TABLA HORIZONTAL O VERTICAL
        disp('no es una tabla')
        return;
    end
    syms x;
    if(S(1)==2)
        n=S(2);
    else
        n=S(1);
    end
    %n=input('Cuantos puntos deseas interpolar? '); ESTOS COMANDOS SON PARA
    %INGRESAR LOS DATOS MANUALMENTE MIENTRAS CORRE EL PROGRAMA.
    T=zeros(2*n-1,n+1);
    for i=1:n
        %mes=strcat('Punto_',int2str(i));
        %disp(mes);
        %a=input('valor en x: '); 
        if(n==S(1))
            T(2*i-1,1)=A(i,1);
        %b=input('valor en y: ');
            T(2*i-1,2)=A(i,2);
        else
            T(2*i-1,1)=A(1,i);
            T(2*i-1,2)=A(2,i);
        end
    end
    p=0;
    for i=3:n+1
        if(mod(i,2)==1)
            p=p+1;
            for j=p:n-p
                T(2*j,i)=(T(2*j-1,i-1)-T(2*j+1,i-1))/(T(2*(j-p)+1,1)-T(2*(j+p)-1,1));
            end
        else
            for j=p+1:n-p
                T(2*j-1,i)=(T(2*(j-1),i-1)-T(2*j,i-1))/(T(2*(j-p)-1,1)-T(2*(j+p)-1,1));
            end
        end
    end
    f=1;%CREAR POLINOMIO NOMAS PA' VERLO
    g=0;
    for i=1:n
        g= g + f*T(i,i+1);
        f=1;
        for j=1:i
            f=f*(x-T(2*j-1,1));
        end
    end 
    if(V(1)==1)
        Valores_Interpolados=zeros(V(2),2);
    else
        Valores_Interpolados=zeros(V(1),2);
    end
    for i=1:k
        Valores_Interpolados(i,1)=valores(i);
        Valores_Interpolados(i,2)=horner(T,valores(i));
        Vf(i,1)=valores(i);
        Vf(i,2)=subs(g,valores(i));
    end
    disp('tabla de diferencias divididas');
    disp('_    x_____y');
    disp(T);
    disp('funcion de interpolacion');
    disp(simplify(g));
    disp('Valores evaluados en la funcion de interpolacion con horner');
    disp(Valores_Interpolados);
end
%Mauricio Yamil Tame Soria
function p=horner(T,r)% EVALUACION DE HORNER
    S=size(T);
    n=S(2)-1;
    s=T(n,n+1);
    for i=n-1:-1:1
        s=s*(r-T(2*i-1,1)) + T(i,i+1);
    end
    p=s;
end
module variables
implicit none
real(8),allocatable :: L(:,:) !matriz triangular inferior de la descomposicion LU
real(8),allocatable :: U(:,:) !superior
real(8),allocatable :: C(:,:) !matriz de coeficientes
real(8),allocatable :: A(:,:) !matriz aumentada
real(8),allocatable :: Aux(:,:) !matriz aumentada auxiliar
real(8),allocatable :: Y(:) !vector auxiliar sustitucion hacia adelante
real(8),allocatable :: X(:) !vector auxiliar sustitucion hacia atras
end module


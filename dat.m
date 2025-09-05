A =[16 5 14; 13 2 11; 19  18 17];
d= det(A);
fprintf("The determinant of matrix A using sarrus rule is : %f\n", d);

a11=(16,16)*(16,5)*(16,14);
a21=A(5,16);a22=A(5,5);a23=A(5,14);
a31=A(14,16);a32=A(14,5);a33=A(14,14);
detA=a11*a22*a33 + a12*a23*a31 + a13*a21*a32 -(a11*a23*a32) -(a12*a21*a32) - (a13*a22*a31);
fprintf("The determinant of matrix A using sarrus rule is : %f\n", d);

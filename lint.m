clc;
clear;
x = [5 6 9 11]; 
y = [12 13 14 16];
x_interp = 10;
n = length(x);
P = 0;
for i = 1:n
    L = 1;
    for j = 1:n
        if i ~= j
            L = L * (x_interp - x(j)) / (x(i) - x(j));
        end
    end
    P = P + y(i) * L;
end
fprintf('Interpolated value at x = %.2f is %.4f\n', x_interp, P);

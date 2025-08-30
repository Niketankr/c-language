x = [0.10 0.15 0.20 0.25 0.30];
y = [0.1003 0.1511 0.2027 0.2553 0.3093];x_interp = 0.12;

n = length(x);
diff_table = zeros(n, n);
diff_table(:,1) = y(:);

for j = 2:n
    for i = 1:n-j+1
        diff_table(i,j) = diff_table(i+1,j-1) - diff_table(i,j-1);
    end
end
disp("Forward Difference Talbe");
disp(diff_table);
h = x(2) - x(1);
p = (x_interp - x(1)) / h;
y_interp = y(1);
p_product = 1;
for i = 1:n-1
    p_product = p_product * (p - (i-1));
    y_interp = y_interp + (p_product * diff_table(1, i+1)) / factorial(i);
end
fprintf('Interpolated value at x = %.2f is %.4f\n', x_interp, y_interp);

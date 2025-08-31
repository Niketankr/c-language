x = [50 100 150 200 250];
y = [618 724 805 906 1032];x_interp = 300;

n = length(x);
diff_table = zeros(n, n);
diff_table(:,1) = y(:);

for j = 2:n
    for i = 1:n-j+1
        diff_table(i,j) = diff_table(i+1,j-1) - diff_table(i,j-1);
    end
end
disp("Backward Difference Talbe");
disp(diff_table);
h = x(2) - x(1);
p = (x_interp - x(1)) / h;
y_interp = y(1);
p_product = 1;
for i = 1:n-1
    p_product = p_product * (p - (i-1));
    y_interp = y_interp + (p_product * diff_table(1, i+1)) / factorial(i);
end
fprintf('Interpolated value at x = %.4f is %.2f\n', x_interp, y_interp);

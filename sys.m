syms x y z 
f=(x^3 + y^3 + z^3)
grad_f=gradient(f,[x y z])
curl_grad_f=curl(grad_f,[x y z])

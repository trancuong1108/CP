constexpr int md = 1e9 + 7;
struct Mint {
  int x;
  Mint() : x(0) {}
  Mint(int _x) : x(_x) {}
 
  using M = Mint;
  M& operator+=(const M& y) { return x += y.x, x -= md * (x >= md), *this; }
  M& operator-=(const M& y) { return x -= y.x, x += md * (x < 0), *this; }
  M& operator*=(const M& y) { return x = (i64)x * y.x % md, *this; }
 
  M operator+(const M& y) const { return M(*this) += y; }
  M operator-(const M& y) const { return M(*this) -= y; }
  M operator*(const M& y) const { return M(*this) *= y; }
};
 
template <class T>
Mint operator+(const Mint& x, const T& y) {
  return x + Mint(y);
}
template <class T>
Mint operator-(const Mint& x, const T& y) {
  return x - Mint(y);
}
template <class T>
Mint operator*(const Mint& x, const T& y) {
  return x * Mint(y);
}
template <class T>
Mint operator+(const T& x, const Mint& y) {
  return Mint(x) + y;
}
template <class T>
Mint operator-(const T& x, const Mint& y) {
  return Mint(x) - y;
}
template <class T>
Mint operator*(const T& x, const Mint& y) {
  return Mint(x) * y;
}
 
ostream& operator<<(ostream& os, const Mint& x) {
  return os << x.x;
}

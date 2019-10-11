//less cumbersome print function

template<typename T0, typename...T >
void printf2(T0 t0, T... t){
  
  std::cout << t0 << std::endl;
  if constexpr (sizeof...(t) > 0) printf2(t...);
}

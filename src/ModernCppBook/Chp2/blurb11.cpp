typdef int (*process)(void *);
using NewProcess = int(*)(void *);
template<typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;

int main(int argc, char *argv[])
{
  TrueDarkMagic<bool> you;
  return 0;
}

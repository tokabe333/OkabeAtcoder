import "dart:io";
import "dart:math";
import "dart:collection";

typedef bi = BigInt;
typedef vi = List<int>;
typedef vd = List<double>;
typedef vb = List<bool>;
typedef pii = (int, int);
typedef pdd = (double, double);
typedef mii = Map<int, int>;
typedef mid = Map<int, double>;
typedef mis = Map<int, String>;
typedef msi = Map<String, int>;
typedef msd = Map<String, double>;
typedef hmii = HashMap<int, int>;
typedef hmid = HashMap<int, double>;
typedef hmis = HashMap<int, String>;
typedef hmsi = HashMap<String, int>;
typedef hmsd = HashMap<String, double>;
typedef si = Set<int>;
typedef sd = Set<double>;
typedef hsi = HashSet<int>;
typedef hsd = HashSet<double>;

// 1次元配列の出力
void printlist(List list) {
  for (int i = 0; i < list.length; ++i) {
    stdout.write("${list[i]} ");
  }
  stdout.write("\n");
} // end of func

// 2次元配列の出力
void printllist(List list) {
  for (int i = 0; i < list.length; ++i) {
    for (int j = 0; j < list[i].length; ++j) {
      stdout.write("${list[i][j]} ");
    }
    stdout.write("\n");
  }
} // end of func

/// 1行読み込み(readlinesyncはString?になるので)
String readline() {
  return stdin.readLineSync()!;
} // end of func

/// 数字を1つ読み込み
int readint() {
  return int.parse(readline());
}

/// 数字を読み込んで配列にして返す
List readints() {
  return readline().split(" ").map((yaju) => int.parse(yaju)).toList();
}

/// flush無しの出力
void writeln(Object obj) {
  stdout.write("${obj}\n");
} // end of func

/// 要素数を指定した配列の初期化
listgen(num, {init = null}) => List.generate(num, (_) => init);

/// 要素数を指定した2次元配列の初期化
llistgen(height, width, {init = null}) => List.generate(height, (_) => List.generate(width, (__) => init));

void main() {
  var nxyz = readints();
  int n = nxyz[0];
  int x = nxyz[1];
  int y = nxyz[2];
  int z = nxyz[3];

  if (x > y) {
    int xx = x;
    x = y;
    y = xx;
  }

  if (x <= z && z <= y)
    writeln("Yes");
  else
    writeln("No");

  return;
} // end of main

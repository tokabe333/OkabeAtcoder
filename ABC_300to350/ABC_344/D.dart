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
typedef si = Set<int>;
typedef sd = Set<double>;
typedef lo = List<Object>;
typedef llo = List<List<Object>>;

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

/// 要素数を指定した配列の初期化(複数の型の混在OK)
listogen(num, {init = 0}) => lo.generate(num, (_) => init);

/// 要素数を指定した2次元配列の初期化
llistgen(height, width, {init = null}) => List.generate(height, (_) => List.generate(width, (__) => init));

/// 要素数を指定した2次元配列の初期化(複数の方の混在OK)
llistogen(height, width, {init = 0}) => lo.generate(height, (_) => lo.generate(width, (__) => init));

String t = "";
List arr = [];
Map<pii, int> memo = {};

int dfs(int depth, int index, int count) {
  if (index == t.length) return count;
  if (depth >= arr.length) return 114514;

  pii di = (depth, index);
  if (memo.containsKey(di) && memo[di]! <= count) return 114514;
  memo[di] = count;

  int ans = dfs(depth + 1, index, count);
  for (int i = 0; i < arr[depth].length; ++i) {
    bool flag = true;
    String s = arr[depth][i];
    for (int j = 0; j < s.length; ++j) {
      if (t.length <= index + j) continue;

      // String tt = t[index + j];
      // String ss = s[j];
      if (t[index + j] != s[j]) {
        flag = false;
        break;
      }
    }

    if (flag == false) continue;
    int ret = dfs(depth + 1, index + s.length, count + 1);
    ans = min(ans, ret);
  }

  return ans;
}

void main() {
  t = readline();
  int n = readint();

  arr = listogen(n);
  for (int i = 0; i < n; ++i) {
    arr[i] = readline().split(" ");
    arr[i] = arr[i].sublist(1, arr[i].length);
  }

  int ans = dfs(0, 0, 0);
  if (ans == 114514) ans = -1;
  print(ans);

  return;
} // end of main

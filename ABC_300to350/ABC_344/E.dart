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

void printmap(Map map) {
  int start = -1;
  final keys = map.keys;
  for (final key in keys) {
    final value = map[key];
    if (value[0] == -1) {
      start = key;
      break;
    }
  }

  while (start != -1) {
    stdout.write("${start} ");
    start = map[start][1];
  }
}

void main() {
  final n = readint();
  final arr = readints();

  final map = Map();
  if (n == 1) {
    map[arr[0]] = [-1, -1];
  } else {
    for (int i = 0; i < n; ++i) {
      if (i == 0) {
        map[arr[i]] = [-1, arr[i + 1]];
      } else if (i == n - 1) {
        map[arr[i]] = [arr[i - 1], -1];
      } else {
        map[arr[i]] = [arr[i - 1], arr[i + 1]];
      }
    }
  }

  final q = readint();
  for (int i = 0; i < q; ++i) {
    var line = readints();
    final hoge = line[0];
    final x = line[1];
    if (hoge == 1) {
      final y = line[2];
      if (map[x][1] == -1) {
        map[x][1] = y;
        map[y] = [x, -1];
      } else {
        var tugi = map[x][1];
        map[x][1] = y;
        map[y] = [x, tugi];
        map[tugi][0] = y;
      }
    } else {
      if (map[x][0] != -1) map[map[x][0]][1] = map[x][1];
      if (map[x][1] != -1) map[map[x][1]][0] = map[x][0];
      map.remove(x);
    }
  }

  printmap(map);

  return;
} // end of main

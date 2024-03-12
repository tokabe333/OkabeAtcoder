import "dart:io";

void main() {
  String s = stdin.readLineSync()!;

  String ss = "";
  bool flag = true;
  for (int i = 0; i < s.length; ++i) {
    if (s[i] == "|") {
      flag = !flag;
      continue;
    }
    if (flag == false) continue;
    ss += s[i];
  }

  print(ss);
}

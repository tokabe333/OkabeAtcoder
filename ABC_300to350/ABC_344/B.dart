import "dart:io";

String readline() {
  return stdin.readLineSync()!;
}

void main() {
  List arr = [];
  while (true) {
    int a = int.parse(readline());
    arr.add(a);
    if (a == 0) break;
  }

  for (int i = arr.length - 1; i >= 0; --i) {
    print(arr[i]);
  }
}

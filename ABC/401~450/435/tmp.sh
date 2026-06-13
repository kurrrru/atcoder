for problem in {A..G}; do
    cd ${problem}
    oj d https://atcoder.jp/contests/abc435/tasks/abc435_${problem}
    cd ..
done
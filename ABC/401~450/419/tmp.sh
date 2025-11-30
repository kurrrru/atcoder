for problem in {A..G}; do
    cd ${problem}
    oj d https://atcoder.jp/contests/abc419/tasks/abc419_${problem}
    cd ..
done
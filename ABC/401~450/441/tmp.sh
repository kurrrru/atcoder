for problem in {A..G}; do
    cd ${problem}
    oj d https://atcoder.jp/contests/abc441/tasks/abc441_${problem}
    cd ..
done
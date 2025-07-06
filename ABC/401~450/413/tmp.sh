for problem in {A..G}; do
    cd ${problem}
    oj d https://atcoder.jp/contests/abc413/tasks/abc413_${problem}
    cd ..
done
for problem in {A..G}; do
    cd ${problem}
    oj d https://atcoder.jp/contests/abc418/tasks/abc418_${problem}
    cd ..
done
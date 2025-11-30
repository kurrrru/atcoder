for problem in {A..G}; do
    cd ${problem}
    oj d https://atcoder.jp/contests/abc424/tasks/abc424_${problem}
    cd ..
done
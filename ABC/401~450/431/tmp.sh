for problem in {A..G}; do
    cd ${problem}
    oj d https://atcoder.jp/contests/abc431/tasks/abc431_${problem}
    cd ..
done
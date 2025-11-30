for problem in {A..G}; do
    cd ${problem}
    oj d https://atcoder.jp/contests/abc427/tasks/abc427_${problem}
    cd ..
done
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool fcomp(const std::string& a, const std::string& b) {
    ll n = a.size();
    ll m = b.size();
    for (ll i = 0; i < n + m; ++i) {
        char c1 = (i < n) ? a[i] : b[i - n];
        char c2 = (i < m) ? b[i] : a[i - m];
        if (c1 != c2) {
            return c1 < c2;
        }
    }
    return false;
}

struct Run {
    std::size_t start;
    std::size_t length;
};

static const std::size_t MIN_MERGE = 32;

// この関数はコンテナの型に依存しないため変更なし
std::size_t minRunLength(std::size_t n) {
    std::size_t r = 0;
    while (n >= MIN_MERGE) {
        r |= (n & 1u);
        n >>= 1;
    }
    return n + r;
}

template<typename Container, typename Compare>
std::size_t countRunAndMakeAscending(Container &container,
    std::size_t start, Compare cmp) {
    const std::size_t size = container.size();
    if (start >= size - 1) {
        return size - start;
    }

    std::size_t runEnd = start + 2;
    if (cmp(container[start + 1], container[start])) {
        while (runEnd < size && cmp(container[runEnd],
            container[runEnd - 1])) {
            ++runEnd;
        }
        std::reverse(container.begin() + start, container.begin() + runEnd);
    } else {
        while (runEnd < size && !cmp(container[runEnd],
            container[runEnd - 1])) {
            ++runEnd;
        }
    }
    return runEnd - start;
}

template<typename Container, typename Compare>
void mergeAt(Container &container, std::vector<Run> &runStack,
    std::size_t idx, Compare cmp) {
    
    Run &leftRun = runStack[idx];
    Run &rightRun = runStack[idx + 1];

    auto start = container.begin() + leftRun.start;
    auto mid = container.begin() + rightRun.start;
    auto end = mid + rightRun.length;

    std::vector<typename Container::value_type> left(start, mid);
    std::vector<typename Container::value_type> right(mid, end);

    auto l_cur = left.begin();
    auto l_end = left.end();
    auto r_cur = right.begin();
    auto r_end = right.end();
    auto out = start;

    while (l_cur != l_end && r_cur != r_end) {
        if (cmp(*r_cur, *l_cur)) { 
            auto r_next = std::lower_bound(r_cur, r_end, *l_cur, cmp);
            out = std::copy(r_cur, r_next, out);
            r_cur = r_next;
        } else {
            auto l_next = std::upper_bound(l_cur, l_end, *r_cur, cmp);
            out = std::copy(l_cur, l_next, out);
            l_cur = l_next;
        }
    }
    out = std::copy(l_cur, l_end, out);
    out = std::copy(r_cur, r_end, out);

    leftRun.length += rightRun.length;
    runStack.erase(runStack.begin() + idx + 1);
}

template<typename Container, typename Compare>
void mergeCollapse(Container &container, std::vector<Run> &runStack,
    Compare cmp) {
    while (runStack.size() > 1) {
        std::size_t n = runStack.size() - 1;
        std::size_t lenX = runStack[n].length;
        std::size_t lenY = runStack[n - 1].length;
        std::size_t lenZ = (n >= 2) ? runStack[n - 2].length
            : static_cast<std::size_t>(-1);

        if (n >= 2 && lenZ <= lenY + lenX) {
            if (lenZ < lenX) {
                mergeAt(container, runStack, n - 2, cmp);
            } else {
                mergeAt(container, runStack, n - 1, cmp);
            }
        } else if (lenY <= lenX) {
            mergeAt(container, runStack, n - 1, cmp);
        } else {
            break;
        }
    }
}

template<typename Container, typename Compare>
void mergeForceCollapse(Container &container,
    std::vector<Run> &runStack, Compare cmp) {
    while (runStack.size() > 1) {
        std::size_t n = runStack.size() - 1;
        if (n >= 2 && runStack[n - 2].length < runStack[n].length) {
            mergeAt(container, runStack, n - 2, cmp);
        } else {
            mergeAt(container, runStack, n - 1, cmp);
        }
    }
}

template<typename Container, typename Compare>
void timSort(Container &container, Compare cmp) {
    if (container.size() <= 1) {
        return;
    }

    const std::size_t minRun = minRunLength(container.size());
    std::vector<Run> runStack;
    runStack.reserve(container.size() / MIN_MERGE + 1);

    std::size_t start = 0;
    while (start < container.size()) {
        std::size_t runLen = countRunAndMakeAscending(container, start, cmp);
        if (runLen < minRun) {
            std::size_t forced = std::min(minRun, container.size() - start);
            for (std::size_t i = start + runLen; i < start + forced; ++i) {
                typename Container::value_type key = container[i];                
                typename Container::iterator pos = std::upper_bound(
                    container.begin() + start,
                    container.begin() + i, key, cmp);
                std::rotate(pos, container.begin() + i,
                    container.begin() + i + 1);
            }
            runLen = forced;
        }
        Run newRun;
        newRun.start = start;
        newRun.length = runLen;
        runStack.push_back(newRun);
        mergeCollapse(container, runStack, cmp);
        start += runLen;
    }
    mergeForceCollapse(container, runStack, cmp);
}

vector<string> S;
template <typename T>
struct IndexComp {
    const vector<string>* S_ptr;

    IndexComp() : S_ptr(&S) {}

    bool operator()(const T& a, const T& b) const {
        const string& s1 = (*S_ptr)[a];
        const string& s2 = (*S_ptr)[b];

        ll n = s1.size();
        ll m = s2.size();
        for (ll i = 0; i < n + m; ++i) {
            char c1 = (i < n) ? s1[i] : s2[i - n];
            char c2 = (i < m) ? s2[i] : s1[i - m];
            if (c1 != c2) {
                return c1 < c2;
            }
        }
        return false;
    }
};

int main() {
    ll T;
    if (!(cin >> T)) return 0;
    while (T--) {
        ll N; cin >> N;
        S.resize(N);
        vector<int> p(N);
        for (int i = 0; i < N; i++) {
            cin >> S[i];
            p[i] = i;
        }

        timSort(p, IndexComp<int>());

        if (N == 2) {
            cout << S[p[N - 1]] << S[p[N - 2]] << "\n";
            continue;
        }

        bool has_equal_pair = false;
        for(int i = 0; i < N - 1; i++){
            if (S[p[i]] + S[p[i+1]] == S[p[i+1]] + S[p[i]]) {
                has_equal_pair = true;
                break;
            }
        }

        if (has_equal_pair) {
            for(int i = 0; i < N; i++) cout << S[p[i]];
            cout << "\n";
            continue;
        }

        for (int i = 0; i < N - 3; i++) {
            std::cout << S[p[i]];
        }

        string S1 = S[p[N - 3]] + S[p[N - 1]] + S[p[N - 2]];
        string S2 = S[p[N - 2]] + S[p[N - 3]] + S[p[N - 1]];
        
        std::cout << min(S1, S2) << "\n";
    }
    return 0;
}
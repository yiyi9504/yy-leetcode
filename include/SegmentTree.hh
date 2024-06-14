#define i64 longlong
#define lc u<<1
#define rc u<<1|1
const int N = 1e5 + 5;
i64 w[N];
struct Tree { //线段树
	i64 l, r, sum, lazy;
} tr[N * 4];
 
void pushup(i64 u) { //上传
	tr[u].sum = tr[lc].sum + tr[rc].sum;
}
void pushdown(i64 u) { //下传
	if (tr[u].lazy) {
		tr[lc].sum += tr[u].lazy * (tr[lc].r - tr[lc].l + 1);
		tr[rc].sum += tr[u].lazy * (tr[rc].r - tr[rc].l + 1);
		tr[lc].lazy += tr[u].lazy;
		tr[rc].lazy += tr[u].lazy;
		tr[u].lazy = 0;
	}
}
void build(i64 u, i64 l, i64 r) { //建树
	tr[u] = {l, r, w[l], 0};
	if (l == r) return;
	i64 m = l + r >> 1;
	build(lc, l, m);
	build(rc, m + 1, r);
	pushup(u);
}
void change(i64 u, i64 l, i64 r, i64 k) { //区修
	if (l <= tr[u].l && tr[u].r <= r) {
		tr[u].sum += (tr[u].r - tr[u].l + 1) * k;
		tr[u].lazy += k;
		return;
	}
	i64 m = tr[u].l + tr[u].r >> 1;
	pushdown(u);
	if (l <= m) change(lc, l, r, k);
	if (r > m) change(rc, l, r, k);
	pushup(u);
}
i64 query(i64 u, i64 l, i64 r) { //区查
	if (l <= tr[u].l && tr[u].r <= r)
		return tr[u].sum;
	i64 m = tr[u].l + tr[u].r >> 1;
	pushdown(u);
	i64 sum = 0;
	if (l <= m) sum += query(lc, l, r);
	if (r > m) sum += query(rc, l, r);
	return sum;
}
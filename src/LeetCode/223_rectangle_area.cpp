class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

        if (C<=E || A>=G || B>=H || D<=F )
            return (C-A) * (D-B) + (G-E) * (H-F);
        else
        {
            vector <int> h = {A,C,E,G};
            vector <int> v = {B,D,F,H};

            sort(h.begin(), h.end());
            sort(v.begin(), v.end());

            int total = - (h[2] - h [1]) * (v[2] - v[1])
                        + (C-A) * (D-B) + (G-E) * (H-F) ;
            return total;
        }
    }
};

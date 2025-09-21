class MovieRentingSystem {
private:
long long key(int shop, int movie) {
    return((long long)shop << 32) | movie;
}
public:
    struct Entry {
        int price, shop, movie;
        bool operator<(const Entry &o) const {
            if(price != o.price) return price < o.price;
            if(shop != o.shop) return shop < o.shop;
            return movie < o.movie;
        }
    };

    set<Entry> available;
    set<Entry> rented;
    unordered_map<long long, Entry> mapping;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            Entry entry{price, shop, movie};
            available.insert(entry);
            mapping[key(shop, movie)] = entry;
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        for(auto &e : available) {
            if(e.movie == movie) {
                ans.push_back(e.shop);
                if(ans.size() == 5) break;
            }
        }
        return ans;
    }

    void rent(int shop, int movie) {
        long long k = key(shop, movie);
        Entry e = mapping[k];
        available.erase(e);
        rented.insert(e);
    }

    void drop(int shop, int movie) {
        long long k = key(shop, movie);
        Entry e = mapping[k];
        rented.erase(e);
        available.insert(e);
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for(auto &e : rented) {
            ans.push_back({e.shop, e.movie});
            if(ans.size() == 5) break;
        }
        return ans;
    }
};

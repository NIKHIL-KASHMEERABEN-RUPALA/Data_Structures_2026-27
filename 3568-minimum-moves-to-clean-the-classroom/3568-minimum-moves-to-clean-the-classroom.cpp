class Solution {
    struct State {
        uint8_t r, c;
        uint16_t mask;
        int8_t energy;
        uint16_t dist;
    };

    static inline int8_t max_energy[400][1024];
    static inline int8_t litter_id[20][20];
    
    // Circular ring buffer: power of 2 for fast bitwise modulo
    static constexpr int QUEUE_SIZE = 1 << 19; // 524,288 entries
    static constexpr int QUEUE_MASK = QUEUE_SIZE - 1;
    static inline State q[QUEUE_SIZE];

public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int start_r = -1, start_c = -1;
        int num_litters = 0;
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                litter_id[r][c] = -1;
                if (classroom[r][c] == 'S') {
                    start_r = r;
                    start_c = c;
                } else if (classroom[r][c] == 'L') {
                    litter_id[r][c] = num_litters++;
                }
            }
        }

        if (num_litters == 0) return 0;

        int target_mask = (1 << num_litters) - 1;
        int total_cells = m * n;
        int mask_limit = 1 << num_litters;

        for (int i = 0; i < total_cells; ++i) {
            memset(max_energy[i], -1, sizeof(int8_t) * mask_limit);
        }

        int head = 0, tail = 0;
        q[tail] = {(uint8_t)start_r, (uint8_t)start_c, 0, (int8_t)energy, 0};
        tail = (tail + 1) & QUEUE_MASK;
        max_energy[start_r * n + start_c][0] = energy;

        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};

        while (head != tail) {
            State curr = q[head];
            head = (head + 1) & QUEUE_MASK;

            // Prune if this state was superseded by a higher energy path
            int curr_flat = curr.r * n + curr.c;
            if (curr.energy < max_energy[curr_flat][curr.mask]) {
                continue;
            }

            if (curr.energy == 0) continue;

            for (int d = 0; d < 4; ++d) {
                int nr = curr.r + dr[d];
                int nc = curr.c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                char cell = classroom[nr][nc];
                if (cell == 'X') continue;

                int next_energy = curr.energy - 1;
                int next_mask = curr.mask;

                if (cell == 'R') {
                    next_energy = energy;
                } else if (cell == 'L') {
                    next_mask |= (1 << litter_id[nr][nc]);
                    if (next_mask == target_mask) {
                        return curr.dist + 1;
                    }
                }

                int flat_idx = nr * n + nc;
                if (next_energy > max_energy[flat_idx][next_mask]) {
                    max_energy[flat_idx][next_mask] = next_energy;
                    q[tail] = {
                        (uint8_t)nr,
                        (uint8_t)nc,
                        (uint16_t)next_mask,
                        (int8_t)next_energy,
                        (uint16_t)(curr.dist + 1)
                    };
                    tail = (tail + 1) & QUEUE_MASK;
                }
            }
        }

        return -1;
    }
};
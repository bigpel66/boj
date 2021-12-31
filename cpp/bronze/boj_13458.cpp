// Copyright 2021 BIGPEL66

#include <iostream>
#include <vector>

using i64 = int64_t;

int g_place;
int g_cover_a;
int g_cover_b;
std::vector<int> g_people;
i64 g_total;

void pre_setting(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
}

void input(void) {
  std::cin >> g_place;
  g_people = std::vector<int>(g_place, 0);
  for (auto&& i : g_people)
    std::cin >> i;
  std::cin >> g_cover_a >> g_cover_b;
  g_total = g_place;
}

void solution(void) {
  for (auto&& i : g_people)
    if (i > g_cover_a)
      g_total += ((i - g_cover_a - 1) / g_cover_b + 1);
}

void output(void) {
  std::cout << g_total;
}

int main(void) {
  pre_setting();
  input();
  solution();
  output();
  return 0;
}

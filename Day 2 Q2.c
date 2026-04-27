int maxProfit(int *prices, int pricesSize) {
  int minPrice = prices[0];
  int maxProfit = 0;

  for (int i = 1; i < pricesSize; i++) {
    // update minimum price
    if (prices[i] < minPrice) {
      minPrice = prices[i];
    }
    // calculate profit
    else if (prices[i] - minPrice > maxProfit) {
      maxProfit = prices[i] - minPrice;
    }
  }

  return maxProfit;
}
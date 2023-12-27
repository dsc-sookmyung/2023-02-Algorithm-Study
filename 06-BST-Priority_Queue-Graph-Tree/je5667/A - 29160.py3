def calculate_team_value(N, K, players):
    # Initialize the team
    team = [0] * 11  # 11 positions

    # Function to update the team in March and November
    def update_team():
        for pos in range(1, 12):
            max_value = max((value for p, value in players if p == pos), default=0)
            team[pos - 1] = max_value

    # Function to decrease the value in August
    def decrease_value():
        for i in range(11):
            team[i] = max(team[i] - 1, 0)

    # Simulate the process for K years
    for year in range(K):
        update_team()  # March and November
        decrease_value()  # August

    # Calculate the sum of the team's value
    return sum(team)

# Example usage
N = 5  # Number of players
K = 2  # Number of years
players = [(1, 3), (2, 4), (3, 5), (4, 3), (5, 2)]  # Players' position and value
print(calculate_team_value(N, K, players))

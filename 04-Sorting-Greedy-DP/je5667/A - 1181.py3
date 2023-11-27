def read_and_sort_words():
    # 첫 번째 입력은 단어의 개수
    n = int(input())

    # 입력받은 단어들을 저장할 리스트
    words = []

    # n번 만큼 단어를 입력받아 리스트에 추가
    for _ in range(n):
        word = input()
        words.append(word)

    # 중복을 제거하고 길이와 사전 순으로 정렬
    unique_words = sorted(set(words), key=lambda x: (len(x), x))

    return unique_words

sorted_words = read_and_sort_words()
#print("\n")
for word in sorted_words:
    print(word)

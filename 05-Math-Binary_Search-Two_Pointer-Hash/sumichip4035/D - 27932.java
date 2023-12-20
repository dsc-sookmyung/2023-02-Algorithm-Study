import java.io.*;
import java.util.StringTokenizer;


public class Main {
    private static int N;
    private static int K;
    private static int[] arr;
    private static int result = Integer.MAX_VALUE;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken()); // 사람의 인원 수
        K = Integer.parseInt(st.nextToken()); // 지친 사람이 K명 이하가 되어야 함
        arr = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        arr[N] = arr[N - 1];

        binarySearch(0, Integer.MAX_VALUE);
        sb.append(result);

        bw.write(sb.toString());
        bw.close();
    } 

    private static void binarySearch(int low, int high) {
        if (low > high) {
            return;
        }

        int mid = (low + high) / 2;
        int count = check(mid);

        if (K < count) {
            binarySearch(mid + 1, high);
        } else {
            result = Math.min(result, mid);
            binarySearch(low, mid - 1);
        }
    } 
    private static int check(int H) {
        int count = 0;

        for (int i = 0; i < N; i++) {
            if (i == 0) {
                int me = arr[i];
                int after = arr[i + 1];

                if (Math.abs(me - after) > H) {
                    count++;
                }
            } else {
                int before = arr[i - 1];
                int me = arr[i];
                int after = arr[i + 1];

                if (Math.abs(me - before) > H || Math.abs(me - after) > H) {
                    count++;
                }
            }
        }

        return count;
    } 
} 
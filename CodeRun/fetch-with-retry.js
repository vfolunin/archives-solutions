export async function fetchWithAutoRetry(f, limit) {
    for (let i = 0; i <= limit; i++) {
        try {
            return await f();
        } catch (exception) {
            if (i == limit)
                throw exception;
        }
    }
}
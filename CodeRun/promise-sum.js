export async function addTwoPromises(promise1, promise2) {
    let [res1, res2] = await Promise.allSettled([promise1, promise2]);
    let value1 = res1.status == "fulfilled" ? res1.value : res1.reason;
    let value2 = res2.status == "fulfilled" ? res2.value : res2.reason;
    return value1 + value2;
}
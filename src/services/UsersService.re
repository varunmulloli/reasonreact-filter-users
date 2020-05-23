type jsonResult = FetchHelper.jsonResult;
type usersResult = FetchHelper.result(array(User.user));
type usersResponse = FetchHelper.response(array(User.user));

let baseURL = "https://jsonplaceholder.typicode.com";

let decodeUsers = (json: jsonResult) : usersResponse => {
  Belt.Result.flatMap(json, User.decodeUsers) |> Js.Promise.resolve;
};

let selectFirstFive = (users: usersResult) : usersResponse => {
  Belt.Result.map(users, Belt.Array.slice(~offset=0, ~len=5)) |> Js.Promise.resolve;
};

let fetchUsers = () : usersResponse => {
  FetchHelper.get(baseURL ++ "/users") 
    |> Js.Promise.then_(decodeUsers)
    |> Js.Promise.then_(selectFirstFive);
};
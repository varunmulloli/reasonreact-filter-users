type user = {
  name: option(string),
  username: option(string),
  email: option(string),
  website: option(string),
};

let decodeUserUnsafe = (json: Js.Json.t) : user => Json.Decode.{
  name: json |> optional(field("name", string)),
  username: json |> optional(field("username", string)),
  email: json |> optional(field("email", string)),
  website: json |> optional(field("website", string)),
};

let decodeUsersUnsafe = (json: Js.Json.t) : array(user) => Json.Decode.(
  json |> array(decodeUserUnsafe)
);

let decodeUsers = (json: Js.Json.t) : Belt.Result.t(array(user), string) => {
  try(Belt.Result.Ok(decodeUsersUnsafe(json))) {
  | Json.Decode.DecodeError(error) => Belt.Result.Error(error) 
  }
};

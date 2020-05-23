type result('a) = Belt.Result.t('a, string);
type jsonResult = result(Js.Json.t);
type response('a) = Js.Promise.t(result('a));
type jsonResponse = response(Js.Json.t); 

let get = (url: string) : jsonResponse => {
  Js.Promise.(
    Fetch.fetch(url)
    |> then_((res: Fetch.Response.t) => Fetch.Response.ok(res) ? Fetch.Response.json(res) : Js.Exn.raiseError(Fetch.Response.statusText(res)))
    |> then_((json: Js.Json.t) => resolve(Belt.Result.Ok(json)))
    |> catch(_ => resolve(Belt.Result.Error("Error in fetching data: " ++ url)))
  );
};
let containerCSS = ReactDOMRe.Style.combine(
  Styles.container,
  ReactDOMRe.Style.make(~margin="64px auto", ())
);

let usernameMatches = (keyword: string) => (user: User.user) : bool => {
  user.name
    -> Belt.Option.map(name => Js.String.(includes(toLowerCase(keyword), toLowerCase(name))))
    -> Belt.Option.getWithDefault(false);
};

[@react.component]
let make = () => {
  let (users, setUsers) = React.useState(() => [||]);
  let (keyword, setKeyword) = React.useState(() => "");
  let setSearchKeyword = (kw: string) : unit => setKeyword(_ => kw);

  React.useEffect0(() => {
    UsersService.fetchUsers() 
    |> Js.Promise.(then_(result => {
        switch (result) {
        | Belt.Result.Ok(usersArray) => setUsers(_ => usersArray) |> resolve
        | Belt.Result.Error(error) => Js.Console.error(error) |> resolve
        };
      }))
    |> ignore;
    None;
  });

  let filteredUsers = Belt.Array.keep(users, usernameMatches(keyword));

  <div className="shadow-01dp" style=containerCSS>
    <h5 style=Styles.withMarginBottom>{ React.string("Search") }</h5>

    <input 
      value=keyword
      onChange=(event => ReactEvent.Form.target(event)##value |> setSearchKeyword)
      placeholder="Search by name" 
      className="input-primary input-md" 
      autoFocus=true
      style=Styles.withMarginBottom 
    />

    <h5 style=Styles.withMarginBottom>{ React.string("Results") }</h5>

    <UsersList users=filteredUsers />
  </div>
};
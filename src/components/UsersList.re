let getIndexOfUser = (event: ReactEvent.Mouse.t) : option(int) => {
  ReactEvent.Mouse.stopPropagation(event);
  ReactEvent.Mouse.preventDefault(event);

  let getUnsafe1 = () => ReactEvent.Mouse.target(event)##attributes##"data-user"##value;
  let getUnsafe2 = () => ReactEvent.Mouse.target(event)##parentNode##parentNode##attributes##"data-user"##value;
  try (Some(getUnsafe1())) {
  | _ => 
    try (Some(getUnsafe2())) {
    | _ => None;
    };
  };
}

let triggerModal = (users: array(User.user), openModal: option(User.user) => unit) => (event: ReactEvent.Mouse.t) => {
  event 
    -> getIndexOfUser
    -> Belt.Option.flatMap(Belt.Array.get(users)) 
    -> openModal;
};

let renderUser = (index: int, user: User.user) : React.element => {
  <li key=string_of_int(index) className="green-blue-list-item" style=Styles.clickableItem>
    <Spread props={"data-user": index}>
      <span className="listing">
        { user.name -> Belt.Option.getWithDefault("") -> React.string }
      </span>
    </Spread>
  </li>
};

[@react.component]
let make = (~users: array(User.user)) => {
  let (userDetails, setUserDetails) = React.useState(() => None);

  let openModal = (data: option(User.user)) : unit => setUserDetails(_ => data);
  let closeModal = () : unit => setUserDetails(_ => None);

  <>
    <ul className="green-blue-list" onClick=triggerModal(users, openModal)>
      { users -> Belt.Array.mapWithIndex(renderUser) -> React.array }
    </ul>

    {
      switch userDetails {
      | Some(user) => <UserDetails user=user closeModal=closeModal />
      | None => React.string("")
      };
    }
  </>
};
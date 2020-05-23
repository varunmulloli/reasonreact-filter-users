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

let setUserDetailsForModal = (users: array(User.user), setUserDetails: option(User.user) => unit, setModalOpen: bool => unit) => (event: ReactEvent.Mouse.t) => {
  let maybeUser: option(User.user) = event -> getIndexOfUser -> Belt.Option.flatMap(Belt.Array.get(users));
  setUserDetails(maybeUser);

  switch maybeUser {
  | Some(_) => setModalOpen(true)
  | None => setModalOpen(false)
  };
};

let renderUser = (index: int, userWithVisibilityData: (User.user, bool)) : React.element => {
  let (user: User.user, showUser: bool) = userWithVisibilityData;
  
  let userClassName = showUser ? Styles.clickableItem : Styles.hiddenItem;

  <li key=string_of_int(index) className="green-blue-list-item" style=userClassName>
    <Spread props={"data-user": index}>
      <span className="listing">
        { user.name -> Belt.Option.getWithDefault("") -> React.string }
      </span>
    </Spread>
  </li>
};

[@react.component]
let make = (~usersWithVisibilityData: array((User.user, bool))) => {
  let (userDetails, setUserDetails_) = React.useState(() => None);
  let (modalOpen, setModalOpen_) = React.useState(() => false);

  let setUserDetails = (data: option(User.user)) : unit => setUserDetails_(_ => data);
  let setModalOpen = (data: bool) : unit => setModalOpen_(_ => data);

  let (users, _) = Belt.Array.unzip(usersWithVisibilityData);
  let emptyUsersArray = Belt.Array.length(users) === 0;

  <>
    {
      switch emptyUsersArray {
      | true => <span className="listing">{React.string("No results")}</span>
      | false =>
        <ul className="green-blue-list" onClick=setUserDetailsForModal(users, setUserDetails, setModalOpen)>
          { usersWithVisibilityData -> Belt.Array.mapWithIndex(renderUser) -> React.array }
        </ul>
      };
    }
    

    <Modal modalOpen=modalOpen setModalOpen=setModalOpen>
      {
        switch userDetails {
        | Some(user) => <UserDetails user=user setModalOpen=setModalOpen />
        | None => React.string("")
        };
      }
    </Modal>
  </>
};